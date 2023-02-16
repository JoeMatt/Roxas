// swift-tools-version:5.7

import PackageDescription

let package = Package(
    name: "Roxas",
    defaultLocalization: "us",
    platforms: [
        .iOS(.v12),
        .macOS(.v12),
        .tvOS(.v12),
        .macCatalyst(.v13)
    ],
    products: [
        .library(
            name: "Roxas",
            targets: ["Roxas"]
        ),
        .library(
            name: "RoxasStatic",
            type: .static,
            targets: ["Roxas"]
        ),
        .library(
            name: "RoxasDynamic",
            type: .dynamic,
            targets: ["Roxas"]
        ),
		.library(
			name: "RoxasUI",
			targets: ["RoxasUIKit"]
		),
		.library(
			name: "RoxasUIStatic",
			type: .static,
			targets: ["RoxasUIKit"]
		),
		.library(
			name: "RoxasUIDynamic",
			type: .dynamic,
			targets: ["RoxasUIKit"]
		),
    ],
    dependencies: [],
    targets: [
        .target(
            name: "Roxas",
            dependencies: [
            ],
            linkerSettings: [
                .linkedFramework("Foundation"),
                .linkedFramework("CoreData")
            ]
        ),
		.target(
			name: "RoxasUIKit",
			dependencies: [
				"Roxas",
				.target(name: "Roxas_iOS", condition: .when(platforms: [.iOS, .macCatalyst])),
				.target(name: "Roxas_tvOS", condition: .when(platforms: [.tvOS]))
			],
			linkerSettings: [
				.linkedFramework("UIKit", .when(platforms: [.iOS, .tvOS, .macCatalyst])),
				.linkedFramework("AppKit", .when(platforms: [.macOS])),
				.linkedFramework("Cocoa", .when(platforms: [.macOS])),
				.linkedFramework("Foundation"),
				.linkedFramework("CoreData")
			]
		),
        .target(
            name: "Roxas_iOS",
			linkerSettings: [
				.linkedFramework("UIKit", .when(platforms: [.iOS, .tvOS, .macCatalyst])),
				.linkedFramework("Foundation"),
				.linkedFramework("CoreData")
			]
        ),
        .target(
            name: "Roxas_tvOS",
			linkerSettings: [
				.linkedFramework("UIKit", .when(platforms: [.iOS, .tvOS, .macCatalyst])),
				.linkedFramework("Foundation"),
				.linkedFramework("CoreData")
			]
        ),
        .testTarget(
            name: "RoxasTests",
            dependencies: [
				"Roxas",
				"RoxasUIKit"
			]
        )
    ],
	swiftLanguageVersions: [.v4_2, .v5]
)

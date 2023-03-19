// swift-tools-version:5.7

import PackageDescription

let package = Package(
    name: "Roxas",
    defaultLocalization: "en",
    platforms: [
        .iOS(.v12),
        .macOS(.v12),
        .tvOS(.v12),
        .macCatalyst(.v13)
    ],
    products: [
        // MARK: Roxas
        .library(
            name: "Roxas",
            targets: ["Roxas"]
        ),
        .library(
            name: "Roxas-Static",
            type: .static,
            targets: ["Roxas"]
        ),
        .library(
            name: "Roxas-Dynamic",
            type: .dynamic,
            targets: ["Roxas"]
        ),
        // MARK: RoxasUI
		.library(
			name: "RoxasUI",
			targets: ["RoxasUIKit"]
		),
		.library(
			name: "RoxasUI-Static",
			type: .static,
			targets: ["RoxasUIKit"]
		),
		.library(
			name: "RoxasUI-Dynamic",
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
            name: "Roxas_iOS"
        ),
        .target(
            name: "Roxas_tvOS"
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

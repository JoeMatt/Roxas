// swift-tools-version:5.7

import PackageDescription

let package = Package(
    name: "Roxas",
    defaultLocalization: "us",
    platforms: [
        .iOS(.v14),
        .macOS(.v12),
        .tvOS(.v14),
        .macCatalyst(.v14)
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
//        .library(
//            name: "Roxas_iOS",
//            targets: ["Roxas_iOS"]
//        ),
//        .library(
//            name: "Roxas_tvOS",
//            targets: ["Roxas_tvOS"]
//        ),
    ],
    dependencies: [],
    targets: [
        .target(
            name: "Roxas",
            dependencies: [
                .target(name: "Roxas_iOS", condition: .when(platforms: [.iOS, .macCatalyst])),
                .target(name: "Roxas_tvOS", condition: .when(platforms: [.tvOS]))
            ],
            linkerSettings: [
                .linkedFramework("UIKit", .when(platforms: [.iOS, .tvOS, .macCatalyst])),
                .linkedFramework("AppKit", .when(platforms: [.macOS])),
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
            dependencies: ["Roxas"]
        )
    ]
)

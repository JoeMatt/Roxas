// swift-tools-version:5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Roxas",
    platforms: [
        .iOS(.v11)
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
        )
    ],
    dependencies: [],
    targets: [
        .target(
            name: "Roxas",
            dependencies: [],
            resources: [
                .process("Resources/")
            ],
            linkerSettings: [
                .linkedFramework("UIKit"),
                .linkedFramework("Foundation"),
                .linkedFramework("CoreData")
            ]
        ),
        .testTarget(
            name: "RoxasTests",
            dependencies: ["Roxas"]
        )
    ]
)

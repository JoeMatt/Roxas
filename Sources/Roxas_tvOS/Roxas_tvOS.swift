import Foundation

@objcMembers
@objc public final class Roxas_tvOS: NSObject {
    @objc public class var resources: Bundle {
#if FRAMEWORK
        let bundle = Bundle(for: Roxas_tvOS.self)
#elseif SWIFT_PACKAGE
        let bundle = Bundle.module
#elseif STATIC_LIBRARY
        let bundle: Bundle
        if let bundleURL = Bundle.main.url(forResource: "Roxas_tvOS", withExtension: "bundle") {
            bundle = Bundle(url: bundleURL)!
        } else {
            bundle = .main
        }
#else
        let bundle = Bundle.main
#endif

        return bundle
    }
}

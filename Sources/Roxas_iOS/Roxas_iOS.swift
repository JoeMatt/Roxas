#if os(iOS)
import Foundation

@objcMembers
@objc public final class Roxas_iOS: NSObject {
    public class var resources: Bundle {
        #if FRAMEWORK
            let bundle = Bundle(for: Roxas_iOS.self)
        #elseif SWIFT_PACKAGE
            let bundle = Bundle.module
        #elseif STATIC_LIBRARY
            let bundle: Bundle
            if let bundleURL = Bundle.main.url(forResource: "Roxas_iOS", withExtension: "bundle") {
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
#endif

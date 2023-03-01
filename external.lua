package("systemc")
    set_description("The systemc package")

    add_urls("https://github.com/Xyfuture/systemc-core-xmake.git")
    --add_versions("1.0", "<shasum256 or gitcommit>") 52a2937

    on_install(function (package)
        local configs = {}
        if package:config("shared") then
            configs.kind = "shared"
        end
        import("package.tools.xmake").install(package, configs)
    end)

    on_test(function (package)
        -- TODO check includes and interfaces
        -- assert(package:has_cfuncs("foo", {includes = "foo.h"})
    end)



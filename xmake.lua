add_rules("mode.debug","mode.release")
set_config("mode","debug")
set_config("toolchain","gcc")
set_config("mode","debug")


includes("external.lua")

add_requires("systemc main",{debug=true})
add_requires("nlohmann_json 3.9.1",{debug=true})
add_requires("better-enums 0.11.3",{debug=true})

set_languages("cxx11") -- some bug with cmake


target("ScPIMsim")
    set_kind("binary")
    --add_deps("systemc")
    --add_deps("nlohmann_json")

    add_files("src/**.cpp")
    --add_files("src/**.hpp")
    add_includedirs("src/")
    -- add_includedirs("$(curdir)")

    add_cxxflags("-Wextra", "-Wno-unused-parameter" ,"-Wno-unused-variabl",{tools={"gcc","clang"}})
    add_cxxflags("-std=c++11")

    add_packages("systemc","nlohmann_json","better-enums")
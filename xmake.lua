
add_rules("mode.debug","mode.release")
set_config("mode","debug")
includes("packages/systemc")

target("test")
    set_kind("binary")

    set_toolchains("gcc")

    add_deps("systemc")
    add_files("src/test.cpp")
    -- add_includedirs("$(curdir)")
    set_languages("cxx11")
    add_cxxflags("-Wextra", "-Wno-unused-parameter" ,"-Wno-unused-variabl",{tools={"gcc","clang"}})


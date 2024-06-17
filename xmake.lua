set_project("CollegeHRM")
set_languages("c++20")

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = '.vscode'})

-- The progress of the compiling of the backend.
target("backend")
    set_kind("static")

    add_files("src/lib/*.ixx")
    add_includedirs("src/lib")

    -- Ensure the order to compile.
    before_build(function (target)
        os.exec("xmake build src/lib/employee.ixx")
    end)

-- The main progress.
target("CollegeHRM")
    add_rules("qt.quickapp")
    add_files("src/*.cpp")
    add_files("src/qml.qrc")

    add_deps("backend")
-- Basic info.
set_project("CollegeHRM")
set_languages("cxxlatest")

-- Basic rules, including generating `compile_command.json` automatically.
add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = '.vscode'})
set_config("buildir", "build")
set_config("export_compile_commands", true)

-- Library dependencies.
add_requires("cjson")

-- Target building.
target("CollegeHRM")
    add_rules("qt.quickapp")
    add_files("src/*.cpp")
    add_files("src/qml.qrc")

    add_packages("cjson")
    add_headerfiles("src/lib/*.h")

    -- Automatically generate `qml.qrc`.
    before_build(function (target) 
        if os.host() == 'windows' then
            os.exec('cmd /C ./scripts/generate_qrc.bat')
        else
            os.exec('./scripts/generate_qrc.sh')
        end
    end)
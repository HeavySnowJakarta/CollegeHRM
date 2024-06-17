-- Set project name and language.
set_project("CollegeHRM")
set_languages("cxxlatest")

-- Basic rules, including generating `compile_command.json` automatically.
add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = '.vscode'})
set_config("buildir", "build")
set_config("export_compile_commands", true)

target("CollegeHRM")
    add_rules("qt.quickapp")
    add_files("src/*.cpp")
    add_files("src/qml.qrc")

    add_headerfiles("src/lib/*.h")
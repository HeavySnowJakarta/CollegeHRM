-- Basic info.
set_project("CollegeHRM")
set_languages("cxx17")

-- Basic rules, including generating `compile_command.json` automatically.
add_rules("mode.debug")
add_rules("plugin.compile_commands.autoupdate", {outputdir = '.vscode'})
set_config("buildir", "build")
set_config("export_compile_commands", true)

-- Library dependencies.
add_requires("cjson")

-- Target building with the console frontend.
target("console")
    add_files("src/main_console.cpp")
    add_packages("cjson")
    add_headerfiles("src/lib/backend/*.h")
    add_headerfiles("src/lib/frontend-console/*.h")
    add_files("src/lib/backend/*.cpp")
    add_files("src/lib/frontend-console/*.cpp")

-- Target building with the Qt frontend.
target("qt")
    add_rules("qt.application")
    add_rules("qt.moc")
    add_files("src/main_qt.cpp")
    add_files("src/qml.qrc")

    add_packages("cjson")
    add_headerfiles("src/lib/backend/*.h")
    add_headerfiles("src/lib/frontend-qt/*.h")
    add_files("src/lib/backend/*.cpp")
    add_files("src/lib/frontend-qt/*.cpp")

    -- Temp debug settings.
    add_defines("QT_DEBUG")
    set_symbols("debug")       -- Add debug symbols
    set_optimize("none") 
    add_ldflags("/SUBSYSTEM:CONSOLE") 

    -- Automatically generate `qml.qrc`.
    --[[
    before_build(function (target) 
        if os.host() == 'windows' then
            os.exec('cmd /C scripts\\generate_qrc.bat')
        else
            os.exec('./scripts/generate_qrc.sh')
        end
    end)
    ]]

    -- Ensure MSVC uses correct C++ standard and sets __cplusplus correctly
    -- if is_plat("windows") then
    --     add_cxflags("/Zc:__cplusplus", "/std:c++17")
    -- end

    -- TODO: Ensure the include path to be proper.
    add_includedirs("C:\\Qt\\6.7.1\\msvc2019_64\\include\\QtWidgets")
    -- add_frameworks("QTWidgets")
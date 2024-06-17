-- Project name and language.
set_project("CollegeHRM")
set_languages("c++20")

-- Basic rules, including generating `compile_command.json` automatically.
add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = '.vscode'})
set_config("buildir", "build")
set_config("export_compile_commands", true)

-- Define a rule to ensure modules are compiled and put into right
-- directories.
rule("cpp20module")
    set_extensions(".ixx")
    on_build_file(function(target, sourcefile)
        import("core.project.depend")
        import("core.tool.compiler")
        local dependinfo = depend.load(target, sourcefile, {include = true})
        local compinst = compiler.load("cxx", {target = target})
        local objectfile = path.join(
            target:autogendir(),
            "rules",
            "modules",
            path.basename(sourcefile) .. ".obj"
        )
        depend.save(target, objectfile, dependinfo)
        os.vexecv(compinst:compcmd({sourcefile, "-Fo" .. objectfile, "-c"}))
    end)

-- The progress of the compiling of the backend.
target("backend")
    set_kind("static")
    add_files("src/lib/*.ixx", {rules = "cpp20module"})
    add_includedirs("$(buildir)/$(os)/$(arch)/$(mode)")

-- The main progress.
target("CollegeHRM")
    add_rules("qt.quickapp")
    add_files("src/*.cpp")
    add_files("src/qml.qrc")

    add_deps("backend")
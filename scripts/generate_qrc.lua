-- As `qml.qrc` does not support wildcards, we have to put the files into
-- `qml.qrc` mannually, and that's what this script does.

local lfs = require("lfs")

local src_root_path = "../src/"
local qrc_file_name = "qml.qrc"

-- Open the file and get ready to write.

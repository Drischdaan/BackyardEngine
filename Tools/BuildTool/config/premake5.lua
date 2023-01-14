include 'variables.lua'
include 'functions.lua'

-- Workspace
include 'workspace.lua'

-- Projects
group ''
  include 'projects/engine.lua'
  include 'projects/editor.lua'

group 'Dependencies'
  include 'projects/spdlog.lua'
  include 'projects/glfw.lua'
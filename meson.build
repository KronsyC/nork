project('nork', 'cpp',
  version : '0.1',
  default_options : ['warning_level=1',
                     'cpp_std=c++17'])

# Add QT Dep
qt6 = import('qt6')
qt6_dep = dependency('qt6', modules : ['Core', 'Gui', 'Qml'])

sources = files(
  'src/main.cc',
)

qrc_sources = files(
  'ui/qml.qrc'
)

# QT Resources file for QML 

qresources = qt6.compile_resources(
  name: 'qresources',
  sources: qrc_sources
)

incdir = include_directories('include')

sources += qresources

exe = executable('nork', sources,
  install : true,
  include_directories: incdir,
  dependencies: [
    qt6_dep,
  ]
    
)

test('basic', exe)

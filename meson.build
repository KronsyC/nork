project('nork', 'cpp',
  version : '0.1',
  default_options : ['warning_level=1',
                     'cpp_std=c++20'])

# Add QT Dep
qt6 = import('qt6')
qt6_dep = dependency('qt6', modules : ['Core', 'Gui', 'Qml'])


incdir = include_directories('include')

sources = files(
  'src/main.cc',
  'src/register.cc',

  'src/ui/mainwindow.cc',
  'src/ui/minimap.cc',
  'src/ui/display.cc',
  'src/ui/duck.cc',
  'src/ui/inventory.cc',

  'src/location/location.cc',
  'src/location/loader.cc',

  'src/item/item.cc',
  'src/item/loader.cc',
  'src/loader.cc',

  'src/events.cc'
)

qrc_sources = files(
  'resources/ui/qml.qrc',
  'resources/images/images.qrc',
  'resources/locations/locations.qrc',
  'resources/ducks/ducks.qrc',
  'resources/encounters/encounters.qrc'
)

subdir('include/ui')
# moc_files = import('include/ui/moc.meson')

moc_files = qt6.compile_moc(headers : moc_files,
                            include_directories: incdir,
                            dependencies: qt6_dep)

# QT Resources file for QML 

qresources = qt6.compile_resources(
  name: 'qresources',
  sources: qrc_sources
)


sources += qresources
sources += moc_files

exe = executable('nork', sources,
  install : true,
  include_directories: incdir,
  dependencies: [
    qt6_dep,
  ]
    
)

test('basic', exe)

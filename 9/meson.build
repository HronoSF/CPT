project (
    'myproject', # название проекта
    'cpp', # язык
    version: '0.1.0', # версия кода
    meson_version: '>=0,46', # минимальнаподдерживаемая версия meson
    default_options: ['cpp_std=c++11'] # используемый стандарт С++
)
subdir('src')

doxyfile = configuration_data()
doxyfile.set('OUTPUT_DIRECTORY', meson.build_root())

configure_file(input: 'Doxyfile.in', output: 'Doxyfile',configuration: doxyfile)

doxygen = find_program('doxygen')
if doxygen.found()
    run_target('doc', command: [doxygen,join_paths(meson.build_root(), 'Doxyfile'),'&&','sensible-browser', join_paths(meson.build_root(),'html','index.html')])
endif



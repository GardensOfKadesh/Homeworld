python = find_program('python', required: true)

script_assets_homeworldsdl_big_generate = files('generate_file_list.py')

asset_homeworldsdl_big = custom_target('HomeworldSDL.big',
                                       output: 'HomeworldSDL.big',
                                       command: [python, script_assets_homeworldsdl_big_generate, exe_tools_biggie, '@OUTPUT@'],
                                       depends: [exe_tools_biggie])

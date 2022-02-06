tutorial_01_kp = custom_target('Tutorial1.kp',
                               input: 'Tutorial1.kas',
                               output: 'Tutorial1.kp',
                               capture: true,
                               command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

tutorial_01 = custom_target('Tutorial1',
                            depends: [exe_tools_kas2c, tutorial_01_kp],
                            input: tutorial_01_kp,
                            output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                            command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

src_missions_tutorials = [tutorial_01[0], tutorial_01[2]]

inc_src_missions_tutorials = include_directories('.')

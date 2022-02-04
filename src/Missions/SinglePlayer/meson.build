mission_01_kp = custom_target('Mission01.kp',
                              input: 'Mission01.kas',
                              output: 'Mission01.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_02_kp = custom_target('Mission02.kp',
                              input: 'Mission02.kas',
                              output: 'Mission02.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_03_kp = custom_target('Mission03.kp',
                              input: 'Mission03.kas',
                              output: 'Mission03.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_04_kp = custom_target('Mission04.kp',
                              input: 'Mission04.kas',
                              output: 'Mission04.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_05_kp = custom_target('Mission05.kp',
                              input: 'Mission05.kas',
                              output: 'Mission05.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_05_oem_kp = custom_target('Mission05_OEM.kp',
                                  input: 'Mission05_OEM.kas',
                                  output: 'Mission05_OEM.kp',
                                  capture: true,
                                  command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_06_kp = custom_target('Mission06.kp',
                              input: 'Mission06.kas',
                              output: 'Mission06.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_07_kp = custom_target('Mission07.kp',
                              input: 'Mission07.kas',
                              output: 'Mission07.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_08_kp = custom_target('Mission08.kp',
                              input: 'Mission08.kas',
                              output: 'Mission08.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_09_kp = custom_target('Mission09.kp',
                              input: 'Mission09.kas',
                              output: 'Mission09.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_10_kp = custom_target('Mission10.kp',
                              input: 'Mission10.kas',
                              output: 'Mission10.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_11_kp = custom_target('Mission11.kp',
                              input: 'Mission11.kas',
                              output: 'Mission11.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_12_kp = custom_target('Mission12.kp',
                              input: 'Mission12.kas',
                              output: 'Mission12.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_13_kp = custom_target('Mission13.kp',
                              input: 'Mission13.kas',
                              output: 'Mission13.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_14_kp = custom_target('Mission14.kp',
                              input: 'Mission14.kas',
                              output: 'Mission14.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_15_kp = custom_target('Mission15.kp',
                              input: 'Mission15.kas',
                              output: 'Mission15.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_16_kp = custom_target('Mission16.kp',
                              input: 'Mission16.kas',
                              output: 'Mission16.kp',
                              capture: true,
                              command: [meson.get_compiler('c').cmd_array(), '-E', '-x', 'c', '@INPUT@'])

mission_01 = custom_target('Mission01',
                           depends: [exe_tools_kas2c, mission_01_kp],
                           input: mission_01_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_02 = custom_target('Mission02',
                           depends: [exe_tools_kas2c, mission_02_kp],
                           input: mission_02_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_03 = custom_target('Mission03',
                           depends: [exe_tools_kas2c, mission_03_kp],
                           input: mission_03_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_04 = custom_target('Mission04',
                           depends: [exe_tools_kas2c, mission_04_kp],
                           input: mission_04_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_05 = custom_target('Mission05',
                           depends: [exe_tools_kas2c, mission_05_kp],
                           input: mission_05_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_05_oem = custom_target('Mission05_OEM',
                               depends: [exe_tools_kas2c, mission_05_oem_kp],
                               input: mission_05_oem_kp,
                               output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                               command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_06 = custom_target('Mission06',
                           depends: [exe_tools_kas2c, mission_06_kp],
                           input: mission_06_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_07 = custom_target('Mission07',
                           depends: [exe_tools_kas2c, mission_07_kp],
                           input: mission_07_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_08 = custom_target('Mission08',
                           depends: [exe_tools_kas2c, mission_08_kp],
                           input: mission_08_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_09 = custom_target('Mission09',
                           depends: [exe_tools_kas2c, mission_09_kp],
                           input: mission_09_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_10 = custom_target('Mission10',
                           depends: [exe_tools_kas2c, mission_10_kp],
                           input: mission_10_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_11 = custom_target('Mission11',
                           depends: [exe_tools_kas2c, mission_11_kp],
                           input: mission_11_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_12 = custom_target('Mission12',
                           depends: [exe_tools_kas2c, mission_12_kp],
                           input: mission_12_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_13 = custom_target('Mission13',
                           depends: [exe_tools_kas2c, mission_13_kp],
                           input: mission_13_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_14 = custom_target('Mission14',
                           depends: [exe_tools_kas2c, mission_14_kp],
                           input: mission_14_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_15 = custom_target('Mission15',
                           depends: [exe_tools_kas2c, mission_15_kp],
                           input: mission_15_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

mission_16 = custom_target('Mission16',
                           depends: [exe_tools_kas2c, mission_16_kp],
                           input: mission_16_kp,
                           output: ['@BASENAME@.c', '@BASENAME@.h', '@BASENAME@.func.c'],
                           command: [exe_tools_kas2c, '@INPUT@', '@OUTPUT@'])

src_missions_single_player = [mission_01[0], mission_01[2]]
src_missions_single_player += [mission_02[0], mission_02[2]]
src_missions_single_player += [mission_03[0], mission_03[2]]
src_missions_single_player += [mission_04[0], mission_04[2]]
src_missions_single_player += [mission_05[0], mission_05[2]]
src_missions_single_player += [mission_05_oem[0], mission_05_oem[2]]
src_missions_single_player += [mission_06[0], mission_06[2]]
src_missions_single_player += [mission_07[0], mission_07[2]]
src_missions_single_player += [mission_08[0], mission_08[2]]
src_missions_single_player += [mission_09[0], mission_09[2]]
src_missions_single_player += [mission_10[0], mission_10[2]]
src_missions_single_player += [mission_11[0], mission_11[2]]
src_missions_single_player += [mission_12[0], mission_12[2]]
src_missions_single_player += [mission_13[0], mission_13[2]]
src_missions_single_player += [mission_14[0], mission_14[2]]
src_missions_single_player += [mission_15[0], mission_15[2]]
src_missions_single_player += [mission_16[0], mission_16[2]]

inc_src_missions_single_player = include_directories('.')

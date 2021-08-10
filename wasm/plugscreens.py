
line_spacing = 1.45
line_length = [55, 42]

mode = "md"

font_size = 0
cursor_x = 0
cursor_y = 0

font_pt = [8, 14]


with open("Plugscreens/github-plug-template.md") as file:

    read_line = True
    while read_line:
        read_line = file.readline()

        if "<!---" in read_line:
            mode = "raw"
            continue

        if "--->" in read_line:
            mode = "md"
            continue


        if mode == "raw":

            if "StaticText" in read_line:
                loc_xy = read_line.split()[1]
                #print(loc_xy)
                cursor_x, cursor_y = [int(x) for x in loc_xy.split(',')]
                #print(cursor_x, cursor_y)
            else:
                print(read_line, end='')

        if mode == "md":

            if "## " in read_line:
                font_size = 1
                output_line = read_line[3:]
            else:
                font_size = 0
                output_line = read_line

            if (not output_line.isspace()) and (len(output_line) != 0):
                output_words = output_line.split(' ')

                while len(output_words):
                    cnt = 0
                    output_snippet = ""
                    while (cnt + len(output_words[0])) < line_length[font_size]:
                        tmp = output_words.pop(0)
                        cnt += len(tmp)
                        output_snippet += tmp + " "

                        if len(output_words) == 0: break

                    print("StaticText  %d,%d,%d,%s" % (cursor_x, cursor_y, font_size, output_snippet))
                    cursor_y += round(font_pt[font_size] * line_spacing)

            if font_size == 0:
                cursor_y += font_pt[font_size]

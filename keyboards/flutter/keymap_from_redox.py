import re

with open(r"keyboards\redox\keymaps\18_keys\keymap.c", encoding="utf8") as redox_keymap:
    lines = redox_keymap.read()
lines = re.sub(r"\n( *\/\/.*\n)*", r"\n", lines)
header = re.match(r"(.*?)\[[\_A-Z0-9]+\] = LAYOUT\(.*?[\[\}]", lines, flags=re.DOTALL)[1]
footer = re.match(r".*?const uint16_t PROGMEM keymaps\[\]\[MATRIX_ROWS\]\[MATRIX_COLS\] = \{.*?(};.*)",lines,flags=re.DOTALL)[1]
defs = re.findall(#r"(.*const uint16_t PROGMEM keymaps\[\]\[MATRIX_ROWS\]\[MATRIX_COLS\] = \{.*?)"
                #r"(\[.*?\] = LAYOUT\(.*?\).*?)*",
                #r"(};.*)",
                r"(([\_A-Z0-9]+)\] = LAYOUT\(.*?[\[\}])",
                lines,
                flags=re.DOTALL
                )
layout_18 = []
for match in defs:
    layer, layer_name = match
    cells = layer.split(',')
    layout_18.append(f"""  [{layer_name}] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              """+",".join(cells[28:31]) +",                          " + ",".join(cells[35:38]) + """,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     """ + ",".join(cells[41:45]) +       ",                          " + ",".join(cells[51:55]) + """,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                            """ + ",".join(cells[61:65]) + """
  //                           └────────┴────────┘       └────────┴────────┘""")


output = (header + """
  ),

""".join(layout_18) + """
  )

""" + footer)

print(output)

with open(r"keyboards\flutter\keymaps\from_redox\keymap.c", 'w', encoding="utf8") as out_file:
    out_file.write(output)

for file_name in ("repeat.c", "repeat.h", "rules.mk"):
    with open(rf"keyboards\redox\keymaps\18_keys\{file_name}", encoding="utf8") as in_file:
        with open(rf"keyboards\flutter\keymaps\from_redox\{file_name}", 'w', encoding="utf8") as out_file:
            out_file.write(in_file.read())


#!/usr/bin/env python3
# -*-coding:utf-8 -*


def delete_str(string, characters):
    for i in range(len(characters)):
        string = string.replace(characters[i], "")
    return string


def parse_text():
    lst = []
    with open("periodic_table.txt", "r") as f:
        lines = f.readlines()
        for line in lines:
            lst.append(
                {
                    "name": line.split("=")[0].strip(),
                    "position": delete_str(line.split(":")[1], ", number").strip(),
                    "number": delete_str(line.split(":")[2], ", small").strip(),
                    "small": delete_str(line.split(":")[3], ", molar").strip(),
                    "molar": delete_str(line.split(":")[4], ", electron").strip(),
                    "electron": line.split(":")[5].strip(),
                }
            )
    return lst


def make_one_td(dic):
    lst = [
        "<h4>",
        dic["small"],
        "<br>",
        dic["name"],
        "</h4>\n",
        "<span>",
        "No.",
        dic["number"],
        "</span>\n",
        "\t<ul>\n",
        #'\t\t<li>', dic['small'], '</li>\n',
        "\t\t<li>",
        dic["molar"],
        "</li>\n",
        "\t\t<li>",
        dic["electron"],
        " electron</li>\n",
        "\t</ul>",
    ]
    return "".join(lst)


def make_table(lst_dict):
    position_before = 0
    lst = [
        "<table>\n",
        "<thead>\n",
        "<tr>\n",
        '<th colspan="18">\n',
        '<div class="title">Periodic Table</div>\n',
        "</th>\n",
        "</tr>\n",
        "<tr>\n",
        "<th> 1 </th>\n",
        "<th> 2 </th>\n",
        "<th> 3 </th>\n",
        "<th> 4 </th>\n",
        "<th> 5 </th>\n",
        "<th> 6 </th>\n",
        "<th> 7 </th>\n",
        "<th> 8 </th>\n",
        "<th> 9 </th>\n",
        "<th> 10 </th>\n",
        "<th> 11 </th>\n",
        "<th> 12 </th>\n",
        "<th> 13 </th>\n",
        "<th> 14 </th>\n",
        "<th> 15 </th>\n",
        "<th> 16 </th>\n",
        "<th> 17 </th>\n",
        "<th> 18 </th>\n",
        "</tr>\n",
        "</thead>",
    ]
    for dic in lst_dict:
        td_class = "<td>\n"
        if (int(dic["position"]) - position_before) > 1:
            lst.append(
                '<td colspan="'
                + str(int(dic["position"]) - position_before - 1)
                + '"></td>\n'
            )
        if dic["position"] == "0":
            lst.append("<tr>\n")
        if int(dic["number"]) in [1, 6, 7, 8, 15, 16, 34]:
            td_class = '<td class="class_gas">\n'
        elif int(dic["number"]) in [3, 11, 19, 37, 55, 87]:
            td_class = '<td class="class_alkali">\n'
        elif int(dic["number"]) in [4, 12, 20, 38, 56, 88]:
            td_class = '<td class="class_alkaline">\n'
        elif int(dic["number"]) in [2, 10, 18, 36, 54, 86, 118]:
            td_class = '<td class="class_inert">\n'
        elif int(dic["number"]) in [9, 17, 35, 53, 85, 117]:
            td_class = '<td class="class_hallogen">\n'
        elif int(dic["number"]) in [5, 14, 32, 33, 51, 52, 84]:
            td_class = '<td class="class_metalloid">\n'
        elif int(dic["number"]) in [13, 31, 49, 50, 81, 82, 83, 113, 114, 115, 116]:
            td_class = '<td class="class_post">\n'
        else:
            td_class = '<td class="class_metal">\n'
        lst.append(td_class + make_one_td(dic) + "</td>\n")
        if dic["position"] == "17":
            lst.append("</tr>\n")
        position_before = int(dic["position"])
    lst.append("</table>\n")
    return "".join(lst)


def make_html(lst):
    lst_html = [
        "<!DOCTYPE html>\n",
        '<html lang="en">\n',
        "<head>\n",
        '\t<meta charset="UTF-8">\n',
        "\t<title>periodic table</title>\n",
        '\t<link href="periodic_table.css" rel="stylesheet" />\n',
        "</head>\n",
        "<body>",
    ]
    lst_html.append(make_table(lst))
    lst_html.append("</body>\n" + "</html>")
    return "".join(lst_html)


def periodic_table():
    lst_dict = parse_text()
    str_html = make_html(lst_dict)
    with open("periodic_table.html", "wb") as html:
        html.write(str_html.encode())
    with open("periodic_table.css", "wb") as css:
        css.write(
            "".join(
                [
                    "body {\n",
                    "\tfont-family: sans-serif;\n",
                    "}\n\n",
                    "thead th {\n",
                    "\tfont-size: 40px;\n",
                    "}\n\n",
                    ".title {\n",
                    "\tfont-size: 100px;\n",
                    "}\n\n",
                    "table {\n",
                    "\twidth: 100%;\n",
                    "\tborder-color: black;\n",
                    "\tborder-collapse: collapse;\n",
                    "\tfont-size: 30px;\n",
                    "}\n\n",
                    "td {\n",
                    "\twidth: 5.55555555556%;\n",
                    "\theight: 200px;\n",
                    "\tborder: 4px solid black;\n",
                    "\ttext-align: center;\n",
                    "}\n\n",
                    "ul {\n",
                    "\twidth: 100%;\n",
                    "\ttext-align: center;\n",
                    "\tpadding: 0;\n",
                    "\talign-items: center;\n",
                    "}\n\n" "li {\n",
                    "\tlist-style-type: none;\n",
                    "}\n\n",
                    ".class_gas {\n",
                    "\tbackground-color: aquamarine;\n" "}\n\n" ".class_alkali {\n",
                    "\tbackground-color: #ba6868;\n",
                    "}\n\n" ".class_alkaline {\n",
                    "\tbackground-color: #ffd7a7;\n",
                    "}\n\n" ".class_inert {\n",
                    "\tbackground-color: #befeff;\n",
                    "}\n\n" ".class_hallogen {\n",
                    "\tbackground-color: #eedbb0;\n",
                    "}\n\n" ".class_metalloid {\n",
                    "\tbackground-color: #80745b;\n",
                    "}\n\n" ".class_post {\n",
                    "\tbackground-color: #424242;\n",
                    "\tcolor: white;\n",
                    "}\n\n" ".class_metal {\n",
                    "\tbackground-color: #edabab;\n",
                    "}\n\n",
                ]
            ).encode()
        )


if __name__ == "__main__":
    periodic_table()

def delete_str(string, characters):
	for i in range(len(characters)):
		string = string.replace(characters[i], "")
	return string

def parse_text():
	lst = []
	with open('periodic_table.txt', 'r') as f:
		lines = f.readlines()
		for line in lines:
			lst.append(
				{
					'name' : line.split('=')[0].strip(),
					'position' : delete_str(line.split(':')[1], ", number").strip(),
					'number' : delete_str(line.split(':')[2], ", small").strip(),
					'small' : delete_str(line.split(':')[3], ", molar").strip(),
					'molar' : delete_str(line.split(':')[4], ", electron").strip(),
					'electron' : line.split(':')[5].strip()
				}
			)
	return lst

def make_one_td(dic):
	lst = [
		'<h4>', dic['small'], '<br>', dic['name'], '</h4>\n',
		'<span>', 'No.', dic['number'], '</span>\n',
		'\t<ul>\n',
		#'\t\t<li>', dic['small'], '</li>\n',
		'\t\t<li>', dic['molar'], '</li>\n',
		'\t\t<li>', dic['electron'], ' electron</li>\n',
		'\t</ul>'
	]
	return ''.join(lst)

def make_table(lst_dict):
	position_before = 0
	lst = [
		'<table>\n',
		'<thead>\n',
		'<tr>\n',
		'<th colspan="18">\n',
		'Periodic Table\n',
		'</th>\n',
		'</tr>\n',
		'</thead>'
	]
	for dic in lst_dict:
		if ((int(dic['position']) - position_before) > 1):
			lst.append(
				'<td colspan="' +
				str(int(dic['position']) - position_before - 1) +
				'"></td>\n'
			)
		if dic['position'] == '0':
			lst.append('<tr>\n')
		lst.append(
			'<td>\n' +
			make_one_td(dic) +
			'</td>\n'
		)
		if dic['position'] == '17':
			lst.append('</tr>\n')
		position_before = int(dic['position'])
	lst.append('</table>\n')
	return ''.join(lst)


def make_html(lst):
	lst_html = [
		'<!DOCTYPE html>\n',
		'<html lang="en">\n',
		'<head>\n',
		'\t<meta charset="UTF-8">\n',
		'\t<title>periodic table</title>\n',
		'\t<link href="periodic_table.css" rel="stylesheet" />\n',
		'</head>\n',
		'<body>',
	]
	lst_html.append(make_table(lst))
	lst_html.append(
		'</body>\n'+
		'</html>'
	)
	return ''.join(lst_html)

def periodic_table():
	lst_dict = parse_text()
	str_html = make_html(lst_dict)
	with open('periodic_table.html', 'wb') as html:
		html.write(str_html.encode())
	with open('periodic_table.css', 'wb') as css:
		css.write(''.join(
			[
				'table {\n',
				'\twidth: 100%;\n',
				'\tborder-color: black;\n',
				'\tborder-collapse: collapse;\n',
				'\tfont-size: 30px;\n',
				'}\n',
				'td {\n',
				'\twidth: 5.55555555556%;\n',
				'\theight: 200px;\n',
				'\tborder: 2px solid black;\n',
				'\ttext-align: center;\n',
				'}\n',
				'ul {\n',
				'\twidth: 100%;\n',
				'\ttext-align: center;\n',
				'\talign-items: center;\n',
				'}\n'
				'li {\n',
				'\tlist-style-type: none;\n',
				'}'
			]
		).encode())

if __name__ == '__main__':
	periodic_table()



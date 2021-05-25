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
					'name' : line.split('=')[0].strip()
					'position' : delete_str(line.split(':')[1], ", number").strip()
					'number' : delete_str(line.split(':')[2], ", small").strip()
					'small' : delete_str(line.split(':')[3], ", molar").strip()
					'molar' : delete_str(line.split(':')[4], ", electron").strip()
					'electron' : line.split(':')[5].strip()
				}
			)
		print(lst)

def periodic_table:
	parse_text()



if __name__ == '__main__':
	periodic_table()



import sys, os, re

def get_html(filename):
	dic = {}
	if os.path.splitext(filename)[1] != '.template':
		print("Invalid file extension!")
	elif not os.path.isfile(filename):
		print("no file available!")
	else:
		try:
			with open('settings.py', 'r') as setting:
				lines = setting.readlines()
				for line in lines:
					if len(line.split('=')) == 2:
						dic[line.split('=')[0].strip()] = line.split('=')[1].strip(' "\n')
			with open(filename, 'r') as template:
				string_template = template.read()
				for item in dic.items():
					string_template = re.sub('{' + item[0] + '}', item[1], string_template)
			with open(os.path.splitext(filename)[0] + '.html', 'wb') as html:
				html.write(string_template.encode())
		except:
			print("File read Error!!")

def render(arg):
	if len(arg) > 2:
		print("too many arguments!")
	elif len(arg) < 2:
		print("no arguments!")
	else:
		get_html(arg[1])

if __name__ == '__main__':
	render(sys.argv)

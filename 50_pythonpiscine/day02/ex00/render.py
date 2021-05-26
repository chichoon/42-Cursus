




def get_html(filename):
	dic = {}
	if os.path.splitext(filename) != 'template':
		print("Invalid file extension!")
	try:
		with open('settings.py', 'r') as setting:
			lines = setting.readlines()
			for line in lines:
				dic[line.split('=')[0].strip()] = line.split('=')[1].strip(' "\n')
			print(dic)
		with open(filename, 'r') as template:
			string_template = template.read()
			list_to_change = ["{name}", "{surname}", "{age}", "{profession}", "{title}", "{title_resume}", "{career}" ]
			#re.sub(string_template, )
	except:
		print("There's no file!")


def render(arg):
	if len(arg) > 2:
		print("too many arguments!")
	elif len(arg) < 2:
		print("no arguments!")
	else:
		get_html(arg[1])



if __name__ == '__main__':
	import sys, os, re
	render(sys.argv)

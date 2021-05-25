import sys

def all_in(arg):
	states = {
	"Oregon" : "OR",
	"Alabama" : "AL",
	"New Jersey": "NJ",
	"Colorado" : "CO"
	}
	capital_cities = {
	"OR": "Salem",
	"AL": "Montgomery",
	"NJ": "Trenton",
	"CO": "Denver"
	}
	if len(sys.argv) == 2:
		arg_list = [name.strip() for name in sys.argv[1].split(',')]
		for arg in arg_list:
			flag = 0
			arg2 = arg.title()
			if arg2:
				for key, value in capital_cities.items():
					if arg2 == value:
						for key2, value2 in states.items():
							if key == value2:
								print(value + " is the capital of " + key2)
								flag = 1
				if flag == 0:
					for key, value in states.items():
						if arg2 == key:
							for key2, value2 in capital_cities.items():
								if value == key2:
									print(value2 + " is the capital of " + key)
									flag = 1
				if flag == 0:
					print(arg + " is neither a capital city nor a state")

if __name__ == '__main__':
	arg = sys.argv
	all_in(arg)


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
	states_rev = {item[1] : item[0] for item in states.items()}
	capital_rev = {item[1] : item[0] for item in capital_cities.items()}
	if len(sys.argv) == 2:
		arg_list = [name.strip() for name in sys.argv[1].split(',')]
		for arg in arg_list:
			flag = 0
			if arg:
				if capital_cities.get(states.get(arg.title())):
					print(capital_cities.get(states.get(arg.title())) + " is the capital of " + arg.title())
				elif states_rev.get(capital_rev.get(arg.title())):
					print(arg.title() + " is the capital of " + states_rev.get(capital_rev.get(arg.title())))
				else:
					print(arg + " is neither a capital city nor a state")

if __name__ == '__main__':
	import sys
	all_in(sys.argv)

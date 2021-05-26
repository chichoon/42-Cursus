import sys

def capital_city(arg):
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
		if_available = states.get(sys.argv[1])
		if if_available:
			print(capital_cities[if_available])
		else:
			print("Unknown state")

if __name__ == '__main__':
	capital_city(sys.argv)


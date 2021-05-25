import sys

def state(arg):
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
		for key, value in capital_cities.items():
			if sys.argv[1] == value:
				for key2, value2 in states.items():
					if key == value2:
						print(key2)
						return
		print("Unknown capital city")

if __name__ == '__main__':
	arg = sys.argv
	state(arg)


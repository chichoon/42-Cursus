class Intern:
    def __init__(self, string="My name? I’m nobody, an intern, I have no name."):
        self.Name = string

    def __str__(self):
        return self.Name

    class Coffee:
        def __str__(self):
            return "This is the worst coffee you ever tasted."

    def work(self):
        raise Exception("I’m just an intern, I can’t do that...")

    def make_coffee(self):
        return

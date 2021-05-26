def var_to_dict():
    d = [
        ("Hendrix", "1942"),
        ("Allman", "1946"),
        ("King", "1925"),
        ("Clapton", "1945"),
        ("Johnson", "1911"),
        ("Berry", "1926"),
        ("Vaughan", "1954"),
        ("Cooder", "1947"),
        ("Page", "1944"),
        ("Richards", "1943"),
        ("Hammett", "1962"),
        ("Cobain", "1967"),
        ("Garcia", "1942"),
        ("Beck", "1944"),
        ("Santana", "1947"),
        ("Ramone", "1948"),
        ("White", "1975"),
        ("Frusciante", "1970"),
        ("Thompson", "1949"),
        ("Burton", "1939"),
    ]
    dic = {}
    for elements in d:
        if elements[1] in dic:
            dic[elements[1]] = dic[elements[1]] + " " + elements[0]
        else:
            dic[elements[1]] = elements[0]
    for item in dic.items():
        print(item[0] + " : " + item[1])


if __name__ == "__main__":
    var_to_dict()

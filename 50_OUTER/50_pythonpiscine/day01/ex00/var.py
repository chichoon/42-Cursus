#!/usr/bin/env python3
# -*-coding:utf-8 -*


def my_var():
    var_int = 42
    var_str = "42"
    var_st2 = "quarante-deux"
    var_flt = 42.0
    var_boo = True
    var_lst = [42]
    var_dct = {42: 42}
    var_tup = (42,)
    var_set = set()

    print(str(var_int) + " has a type " + str(type(var_int)))
    print(var_str + " has a type " + str(type(var_str)))
    print(var_st2 + " has a type " + str(type(var_st2)))
    print(str(var_flt) + " has a type " + str(type(var_flt)))
    print(str(var_boo) + " has a type " + str(type(var_boo)))
    print(str(var_lst) + " has a type " + str(type(var_lst)))
    print(str(var_dct) + " has a type " + str(type(var_dct)))
    print(str(var_tup) + " has a type " + str(type(var_tup)))
    print(str(var_set) + " has a type " + str(type(var_set)))


if __name__ == "__main__":
    my_var()

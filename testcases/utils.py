import os


def extract_lines(filename):
    with open(filename, 'r') as f:
        testcases = [eval(line.strip()) for line in f.readlines() if line.strip() != '']
    return testcases


def extract_testcases(pythonfile):
    tcf = os.path.join(os.path.dirname(pythonfile), 'inputs.txt')
    of = os.path.join(os.path.dirname(pythonfile), 'outputs.txt')

    inputs = extract_lines(tcf)
    outputs = extract_lines(of)

    ni = len(inputs)
    no = len(outputs)
    nit = ni // no

    test_cases = []
    for i in range(no):
        test_cases.append((inputs[nit*i:nit*(i+1)], outputs[i]))
    return test_cases


def execute_tests(testcases, class_to_test, func, prepare_inp=None, prepare_res=None, prepare_out=None):
    sol = class_to_test()
    fun = getattr(sol, func)
    tc, ftn = 0, 0
    for inp, out in testcases:
        tc += 1
        if prepare_inp is not None:
            inp = prepare_inp(*inp)
        if prepare_out is not None:
            out = prepare_out(out)
        print(inp)
        res = fun(*inp)
        if prepare_res is not None:
            res = prepare_res(res)
        if res != out:
            print(f"Excpected: {out} - Result: {res}")
            print()
        else:
            print("OK")
            ftn += 1
    print(f"{ftn}/{tc} Passed!")
import sys, os, getopt, re
from os import listdir
from os.path import isfile, join

def main(argv):
    try:
        opts, args = getopt.getopt(argv, "ho:", ["help", "output="])
    except getopt.GetoptError as err:
        # print help info and exit
        print(err)
        usage()
        sys.exit(2)
    os.system("echo Starting...")
    for o, a in opts:
        if o in ("-h", "--help"):
            usage()
            sys.exit()
        elif o in ("-o", "--output"):
            cwd = os.getcwd()
            srcpath = cwd + os.sep + "src"
            objpath = cwd + os.sep + "obj"

            # get array of src files and compile into obj dir
            os.system("echo Compiling...")
            files = [ f for f in listdir(srcpath) if isfile(join(srcpath, f)) ]
            os.chdir(objpath)
            obj_str = ''
            for f in files:
                if os.system('g++ -c ' + srcpath + os.sep + f) != 0:
                    assert False, "compile error for " + f
                obj_str += objpath + os.sep + f + " "
            # compile main src into obj dir
            if os.system("g++ -c " + cwd + os.sep + "main.cpp") != 0:
                assert False, "compile error for main.cpp"
            obj_str += objpath + os.sep + "main.o"
            obj_str = re.sub('.cpp', '.o', obj_str)

            # link object files
            os.system("echo Linking...")
            os.chdir(cwd)
            exe_file = a + ".exe"
            if os.system("g++ " + obj_str + " -o " + exe_file) != 0:
                assert False, "link error"

            # run exe file
            os.system("echo Running " + exe_file + "...")
            os.system(cwd + os.sep + exe_file)
            os.system("echo Finished")

        else:
            assert False, "unhandled option"

def usage():
    print("compule_cpp.py -o <exe_name>")

if __name__=='__main__':
    main(sys.argv[1:])
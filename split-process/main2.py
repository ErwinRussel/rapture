import re

# - EXAMPLE lib
# void (*_glVertex3f)() = NULL;
#
# void glVertex3f( GLfloat x, GLfloat y, GLfloat z )
# {
#   if (_glVertex3f == NULL) {
#     void *handle = dlopen("libGL.so", RTLD_LAZY);
#     if (handle) {
#         _glVertex3f = dlsym(handle, "glVertex3f");
#       dlclose(handle);
#     }
# }

# TODO: Add logging thing

class HookLibraryGenerator:

    def __init__(self) -> None:
        super().__init__()
        self.gl_hook_funcs = ""
        self.glx_hook_funcs = ""
        self.gl_header_filename = ""
        self.glx_header_filename = ""
        self.gl_decl_filename = ""
        self.glx_decl_filename = ""
        self.gl_output_filename = ""
        self.glx_output_filename = ""


    def create_function(self, func_type, name, args, inputs):
        if func_type == "void":
                stub_func = '''// -- {name}            
{func_type} {name}({args})
{{
    printf("gl stub called: {name}");
}}\n'''.format(func_type=func_type, name=name, args=args, inputs=inputs)
        else:
            stub_func = '''// -- {name}        
{func_type} {name}({args})
{{
    printf("Glx stub called: {name}");
}}\n'''.format(func_type=func_type, name=name, args=args, inputs=inputs)

        return stub_func

    def write_hook_library(self):
        with open(self.gl_output_filename, "w") as file:
            decl_file = open(self.gl_decl_filename, "r")
            decl = decl_file.read()
            decl_file.close()
            file.write(decl)
            file.write(self.gl_hook_funcs)

        with open(self.glx_output_filename, "w") as file:
            decl_file = open(self.glx_decl_filename, "r")
            decl = decl_file.read()
            decl_file.close()
            file.write(decl)
            file.write(self.glx_hook_funcs)

    # TODO: fix const problem
    def args_to_variables(self, input_vars):
        input_var_list = input_vars.split()
        # fixing const problem by removing all the occurences of const out of list
        try:
            while True:
                input_var_list.remove("const")
        except ValueError:
            pass

        try:
            while True:
                input_var_list.remove("*")
        except ValueError:
            pass

        variables = input_var_list[1::2]
        return " ".join(variables)


    # TODO: Check final library to see what happened
    def read_gl_header(self):
        filename = self.gl_header_filename
        with open(filename) as file:
            lines = file.readlines()

            for line in lines:
                if "GLAPIENTRY " in line and "GLAPI " in line:
                    # TODO: Change this a bit better

                    split_line = line.split(maxsplit=3)
                    func_type = split_line[1]
                    func = split_line[3]
                    name = func[:func.find('(')]
                    args = func[func.find('(')+1:func.find(')')]
                    if args == " void ":
                        args = ""
                        inputs = args
                    else:
                        inputs = self.args_to_variables(args)

                    hook_func = self.create_function(func_type, name, args, inputs)
                    self.gl_hook_funcs += (hook_func + "\n")


    # TODO: Check final library to see what happened
    def read_glx_header(self):
        filename = self.glx_header_filename
        with open(filename) as file:
            lines = file.readlines()

            for line in lines:
                if "extern " in line and ");" in line:
                    split_line = line.split(maxsplit=2)
                    func_type = split_line[1]
                    func = split_line[2]
                    name = func[:func.find('(')]
                    args = func[func.find('(')+1:func.find(')')]
                    if args == " void " or args == "void":
                        args = ""
                        inputs = args
                    else:
                        inputs = self.args_to_variables(args)

                    hook_func = self.create_function(func_type, name, args, inputs)
                    self.glx_hook_funcs += (hook_func + "\n")


# TODO: Add header files
def main():
    hook_gen = HookLibraryGenerator()
    hook_gen.gl_header_filename = "headers/gl.h"
    hook_gen.glx_header_filename = "headers/glx.h"
    hook_gen.gl_decl_filename = "decl/gl_hook_decl.c"
    hook_gen.glx_decl_filename = "decl/glx_hook_decl.c"
    hook_gen.gl_output_filename = "lib2/gl_hook_lib.c"
    hook_gen.glx_output_filename = "lib2/glx_hook_lib.c"
    hook_gen.read_gl_header()
    hook_gen.read_glx_header()
    hook_gen.write_hook_library()

if __name__ == '__main__':
    main()



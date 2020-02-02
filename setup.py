
from distutils.core import setup, Extension

module1 = Extension('spam',
                    sources = ['spam.c'])
module2 = Extension('xor',
                    sources = ['xor.c'],
                    extra_compile_args = ['-O3'])

setup(name = 'Spam',
      version = '1.0',
      description = 'This is a demo package',
      ext_modules = [module1, module2])

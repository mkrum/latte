#! /usr/bin/env python2.7 
import pkgutil
import latte
import latte.make

test = latte.make.model()

package=latte
for importer, modname, ispkg in pkgutil.walk_packages(path=package.__path__,
                                                      prefix=package.__name__+'.',
                                                      onerror=lambda x: None):
    print(modname)


print 'import successful'

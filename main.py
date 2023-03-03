#!/usr/bin/env python3

import sys
import os
# import debug.pySource.pyAmrex as amrex
# import debug.pySource.AmrCoreAdv as aca

def main(argv=['main','inputs']):
    print ('here we are in main.py!')

    print('core')
    # amr_core_adv = aca.mainAmrCoreAdv()
    # print('initdata')
    # amr_core_adv.InitData()
    # amr_core_adv.Evolve()

    # amrex.Finalize()
    # success:
    return(0)
def getid():
    print(os.getpid())

if __name__ == '__main__':
    argv = ['main', 'inputs']
    # main(sys.argv)
    main(argv)

"""\
Pregled korisnih komandi:

* 'fab build'                         kompajlira celokupnu knjigu (u svim podrzanim formatima)
* 'fab novi_zadatak.sa_kolokvijuma'   dodaje novi zadatak sa kolokvijuma
"""

from fabric.api import task

import build
import novi_zadatak
import publish


@task(default=True)
def help():
    from fabric.main import show_commands
    show_commands(__doc__, 'normal')

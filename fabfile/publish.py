from fabric.api import env, task
from fabric.contrib.project import rsync_project


env.hosts = ['pjisp.petarmaric.com']


@task(default=True)
def html():
    rsync_project(
        local_dir='_build/html/',
        remote_dir='~/sites/pjisp.petarmaric.com/zbirka-zadataka/',
        delete=True,
    )

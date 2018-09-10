from sphinxcontrib import googleanalytics as ga


def setup(app):
    ga.setup(app)

    # quickfix until https://bitbucket.org/birkenfeld/sphinx-contrib/issues/199/it-seems-commit-from-2015-08-11-is-not
    # is resolved
    return {'parallel_read_safe': True}

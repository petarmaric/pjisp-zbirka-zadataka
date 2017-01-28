# -*- coding: utf-8 -*-
import sphinx.util.texescape as te


# Inspired by https://gist.github.com/rbonvall/652626
extra_replacements = ur'''
    ≤ \ensuremath{\le}
    ≥ \ensuremath{\ge}
'''


def setup(app):
    replacement_list = [
        tuple(line.strip().split())
        for line in extra_replacements.strip().splitlines()
    ]

    te.tex_replacements += replacement_list
    te.init()
    
    return {'parallel_read_safe': True}

from docutils import nodes
from sphinx.builders import Builder
from sphinx.util import status_iterator


class LintBuilder(Builder):
    name = 'lint'

    def init(self):
        self.warnings = []

    def get_outdated_docs(self):
        return self.env.found_docs

    def write(self, build_docnames, updated_docnames, method='update'):
        for docname in status_iterator(sorted(build_docnames), 'running lint... ', length=len(build_docnames)):
            self.check_doc(docname, self.env.get_doctree(docname))

        for warning in self.warnings:
            self.warn(warning)

    def check_doc(self, docname, doctree):
        for node in doctree.traverse(nodes.literal_block):
            if 'source' not in node:
                continue # Skip inlines, only interested in source code files

            filename = node.get('source')
            source_code = node.astext()

            num_spaces = self.config.lint_recommended_tab_width_in_spaces
            if '\t' in source_code:
                self.warnings.append("%s Tabs are not allowed, use %d spaces for indentation instead!" % (filename, num_spaces))

            max_line_length = self.config.lint_max_line_length
            for row, line in enumerate(source_code.splitlines(), start=1):
                line_length = len(line)
                if line_length > max_line_length:
                    self.warnings.append("%s Line %d is too long (%d > %d)!" % (filename, row, line_length, max_line_length))

    def finish(self):
        if self.warnings and self.config.lint_warnings_are_errors:
            self.app.statuscode = 1


def setup(app):
    app.add_config_value('lint_max_line_length', 80, True)
    app.add_config_value('lint_recommended_tab_width_in_spaces', 4, True)
    app.add_config_value('lint_warnings_are_errors', True, True)

    app.add_builder(LintBuilder)

    return {'parallel_read_safe': True}

{% block pun_naziv %}Zadatak "{{ naziv }}"{% endblock %}
{{ '=' * self.pun_naziv()|length }}

.. include:: zadatak.rst


Primer rešenja
--------------

.. literalinclude:: resenje.c

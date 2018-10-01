FROM ubuntu:18.04

ARG DEBIAN_FRONTEND=noninteractive

RUN \
    # Update the Ubuntu package index
       apt-get update \
    # Install the required Ubuntu packages
    && apt-get install -y \
        # pip
        python-pip \
        # LaTeX
        texlive \
        texlive-fonts-extra \
        texlive-lang-cyrillic \
    # Remove the APT cache to reduce Docker image size
    && rm -rf /var/lib/apt/lists/*

# Install Pipenv
RUN pip install pipenv

WORKDIR /app

# Install the required Python packages
COPY Pipfile Pipfile
COPY Pipfile.lock Pipfile.lock
RUN pipenv install --deploy --system

ENTRYPOINT ["fab"]

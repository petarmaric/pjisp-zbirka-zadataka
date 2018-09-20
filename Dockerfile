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

WORKDIR /app

# Install the required Python packages
COPY requirements.txt requirements.txt
RUN pip install -r requirements.txt

ENTRYPOINT ["fab"]

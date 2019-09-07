# Time-stamp: <2019-09-06 22:50:01 daniel>

#
# Dockerfile
#

# This is the Docker file associated with example projects
# developed for Digimarc

# Auther: Daniel Mendyke [archadious@gmail.com]
# https://github.com/TaurusEight/digimarc


FROM base/archlinux:latest
ADD . /digimarc
RUN pacman-db-upgrade
RUN pacman -Syyu --noconfirm
RUN pacman -S valgrind --noconfirm
RUN pacman -S --noconfirm gcc boost make
RUN make -C /digimarc/src clean
RUN make -C /digimarc/src
RUN make -C /digimarc/src test


=========
mcdevops1
=========

This is the mcdevops1 application.


Building
========

Application
-----------
.. code-block:: console

    $ mkdir build && cd build
    $ cmake -DCMAKE_BUILD_TYPE=Debug ../
    $ cmake --build .
    

Documentation (Doxygen)
-----------------------
.. code-block:: console

    $ cd doc/doxygen
    $ doxygen Doxyfile
 
    
Documenation (Sphinx)
---------------------
.. _Breathe: https://breathe.readthedocs.io/en/latest/

.. code-block:: console

    $ sphinx-build -b html doc/sphinx doc/sphinx/_build/html
    
Doxygen documentation can be integreted into Sphinx using the `Breathe`_
extension.


Running
=======

Application
-----------
.. code-block:: console

    $ cd build
    $ ./mcdevops1 --help


Test Suite
----------
.. code-block:: console

    $ cd build
    $ test/test_mcdevops1

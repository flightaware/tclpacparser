tclpacparser, a Tcl interface to the the pacparser proxy auto-config (PAC) parser
===

tclpacparser provides a Tcl interface to the pacparser library for parsing proxy auto-config (PAC) files and performing proxy lookups against them.

Functionality
---

- Provides a natural Tcl interface
- Simple
- Complete
- Free!

License
---

Open source under the permissive Berkeley copyright, see file LICENSE

Requirements
---
Requires the pacparser C library be installed. (https://github.com/pacparser/pacparser)

Building
---

```sh
autoconf
configure
make
sudo make install
```

For FreeBSD, something like

```sh
./configure --with-tcl=/usr/local/lib/tcl8.6  --mandir=/usr/local/man --enable-symbols
```

Accessing from Tcl
---

```tcl
package require pacparser
```

* **pacparser init**

Initialize the pacparser library.

* **pacparser parse_pac** *string*

Parse a proxy auto-config PAC file contained in *string*.

* **pacparser find_proxy** *url* *host*

Returns a proxy string such as *DIRECT* or *PROXY proxy1.bigcompany.co.uk*

Returns an empty string if the method fails for any reason.

* **pacparser set_my_ip** *ip*

* pacparser cleanup

Cleanup the pacparser library.

Bugs
---

Cleanup isn't automatically invoked upon interpreter deletion.

Code is really new, if simple.

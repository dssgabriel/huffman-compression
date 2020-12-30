(TeX-add-style-hook
 "report"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "11pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("fontenc" "T1") ("ulem" "normalem")))
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "href")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art11"
    "inputenc"
    "fontenc"
    "graphicx"
    "grffile"
    "longtable"
    "wrapfig"
    "rotating"
    "ulem"
    "amsmath"
    "textcomp"
    "amssymb"
    "capt-of"
    "hyperref")
   (LaTeX-add-labels
    "sec:orge08d4ff"
    "sec:org5981d5b"
    "sec:org2c022bc"
    "sec:orgd65097d"
    "sec:org1c30b28"
    "sec:org2ab02df"
    "sec:org2f93d66"
    "sec:org811c970"
    "sec:orgbfd111d"
    "sec:org458f7db"
    "sec:org49180c5"
    "sec:orgec59f3e"
    "fig:cli_output"
    "sec:orgf861fef"
    "sec:org4402b3d"
    "sec:org208ed86"
    "sec:orgcfdbdb9"
    "sec:orgd0cdc62"
    "sec:orga9167bd"
    "sec:org0e9ffc4"
    "sec:org29b6e01"
    "fig:qt_window.png"
    "fig:qt_output.png"
    "sec:orgd824651"
    "sec:orge43361a"
    "sec:org98c2c36"
    "sec:orgd9a66db"
    "sec:orga2e233b"
    "sec:org7e7f144"))
 :latex)


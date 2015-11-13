# -*- coding: utf-8 -*-
"""
Connected components.
"""

import networkx as nx
from networkx.utils.decorators import not_implemented_for
from nxcpy.components import _connected

__all__ = [
        'is_connected'
]

@not_implemented_for('directed')
def is_connected(G):
    """Return True if the graph is connected, false otherwise.

    Parameters
    ----------
    G : NetworkX Graph
       An undirected graph.

    Returns
    -------
    connected : bool
      True if the graph is connected, false otherwise.

    Examples
    --------
    >>> G = nx.path_graph(10)
    >>> print(nxc.is_connected(G))
    True

    See Also
    --------
    connected_components

    Notes
    -----
    For undirected graphs only.

    """
    connected = _connected.is_connected(G)
    return True if connected else False

import networkx as nx
import matplotlib.pyplot as plt
import os

class Graph:
    def __init__(self):
        self.vertices = {}  # Словарь для хранения вершин и их меток
        self.edges = {}     # Словарь для хранения дуг и их весов
        self.adjacency_list = {}  # Список смежности

    def add_vertex(self, name, mark):
        self.vertices[name] = mark
        self.adjacency_list[name] = []

    def add_edge(self, v, w, weight):
        if v not in self.edges:
            self.edges[v] = {}
        self.edges[v][w] = weight
        self.adjacency_list[v].append(w)

    def del_vertex(self, name):
        if name in self.vertices:
            del self.vertices[name]
            # Удаляем все дуги, связанные с этой вершиной
            self.edges = {v: {w: c for w, c in edges.items() if w != name} for v, edges in self.edges.items() if v != name}
            del self.adjacency_list[name]

            # Удаляем вершину из списков смежности других вершин
            for vertex, adjacent_vertices in self.adjacency_list.items():
                self.adjacency_list[vertex] = [adjacent_vertex for adjacent_vertex in adjacent_vertices if adjacent_vertex != name]

    def del_edge(self, v, w):
        if v in self.edges and w in self.edges[v]:
            del self.edges[v][w]
            self.adjacency_list[v] = [vertex for vertex in self.adjacency_list[v] if vertex != w]

    def edit_vertex(self, name, new_mark):
        if name in self.vertices:
            self.vertices[name] = new_mark

    def edit_edge(self, v, w, new_weight):
        if v in self.edges and w in self.edges[v]:
            self.edges[v][w] = new_weight

    def first(self, v):
        if v in self.edges and self.edges[v]:
            return next(iter(self.edges[v]))
        else:
            return "L"

    def next(self, v, i):
        if v in self.edges and i in self.edges[v]:
            next_vertices = list(self.edges[v].keys())
            index_i = next_vertices.index(i)
            if index_i + 1 < len(next_vertices):
                return next_vertices[index_i + 1]
            else:
                return "L"
        else:
            return "L"

    def vertex(self, v, i):
        if v in self.edges and i in self.edges[v]:
            return i
        else:
            return None

    def display(self):
        for vertex, adjacent_vertices in self.adjacency_list.items():
            print(f"{vertex} - {', '.join(adjacent_vertices)}", end='')
            if adjacent_vertices:
                for i in adjacent_vertices:
                    print(f' ({self.edges[vertex][i]})', end = '')
                print()
            else:
                print(' (Null)')


    def calc_diff(self):
        num_vertices = len(self.vertices)
        num_edges = sum(len(edges) for edges in self.edges.values())
        num_connected_components = 0
        visited = set()

        def dfs(vertex):
            nonlocal visited
            visited.add(vertex)
            for neighbor in self.adjacency_list[vertex]:
                if neighbor not in visited:
                    dfs(neighbor)

        for vertex in self.vertices:
            if vertex not in visited:
                num_connected_components += 1
                dfs(vertex)

        cyclomatic_complexity = num_edges - num_vertices + 2 * num_connected_components
        return cyclomatic_complexity
    
    def graph_to_img(self):
        G = nx.DiGraph()

        for vertex, mark in self.vertices.items():
            G.add_node(vertex, label=mark)

        for v, edges in self.edges.items():
            for w, weight in edges.items():
                G.add_edge(v, w, weight=weight)

        pos = nx.spring_layout(G)
        labels = nx.get_edge_attributes(G, 'weight') 

        nx.draw(G, pos, with_labels=True, node_size=700, node_color="skyblue", font_size=10, font_color="black", font_weight="bold")
        nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)

        plt.title("Граф")

        plt.show()

print("---- Пример 1 ----")
g = Graph()
g.add_vertex("A", "Метка 1")
g.add_vertex("B", "Метка 2")
g.add_vertex("C", "Метка 3")
g.add_vertex("D", "Метка 4")
g.add_vertex("E", "Метка 5")
g.add_vertex("F", "Метка 6")
g.add_vertex("G", "Метка 7")
g.add_vertex("H", "Метка 8")

g.add_edge("A", "B", 5)
g.add_edge("B", "C", 8)
g.add_edge("E", "F", 19)
g.add_edge("G", "H", 11)
g.add_edge("B", "F", 2)
g.add_edge("G", "D", 8)
g.add_edge("G", "E", 23)
g.add_edge("E", "H", 14)
g.add_edge("B", "G", 22)
g.add_edge("A", "C", 15)
g.add_edge("A", "D", 25)



g.display()

print(f"Цикломатическая сложность графа: {g.calc_diff()}")

print("\n---- Пример 2 ----")
g2 = Graph()
g2.add_vertex("A", "Метка 1")
g2.add_vertex("B", "Метка 2")
g2.add_vertex("C", "Метка 3")
g2.add_vertex("E", "Метка 5")
g2.add_vertex("F", "Метка 6")
g2.add_vertex("G", "Метка 7")

g2.add_edge("A", "B", 5)
g2.add_edge("B", "C", 8)
g2.add_edge("C", "E", 4)
g2.add_edge("E", "F", 22)
g2.add_edge("G", "F", 12)
g2.add_edge("B", "G", 3)
g2.add_edge("F", "G", 7)

g2.display()

print(f"Цикломатическая сложность графа: {g2.calc_diff()}")

g2.graph_to_img()
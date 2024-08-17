import sys

def dijkstra(graph, source):
    """
    Dijkstra's algorithm to find the shortest-path distances from the source vertex to all other vertices.

    Args:
        graph (dict): Adjacency list representation of the graph.
        source (int): Source vertex.

    Returns:
        distances (dict): Shortest-path distances from the source vertex to all other vertices.
    """
    num_vertices = len(graph)
    distances = {vertex: sys.maxsize for vertex in range(1, num_vertices + 1)}
    distances[source] = 0

    for _ in range(num_vertices - 1):
        for vertex in range(1, num_vertices + 1):
            for neighbor, weight in graph[vertex]:
                distances[neighbor] = min(distances[neighbor], distances[vertex] + weight)

    return distances

def main():
    # Read the graph from the file
    graph = {}
    with open("C:\\Users\\aravs\\Downloads\\_dcf1d02570e57d23ab526b1e33ba6f12_dijkstraData.txt", "r") as f:
        for line in f:
            vertex, *neighbors = line.strip().split()
            vertex = int(vertex)
            graph[vertex] = []
            for neighbor in neighbors:
                neighbor_vertex, weight = map(int, neighbor.split(","))
                graph[vertex].append((neighbor_vertex, weight))

    # Run Dijkstra's algorithm
    source = 1
    distances = dijkstra(graph, source)

    # Report the shortest-path distances to the specified vertices
    vertices_to_report = [7, 37, 59, 82, 99, 115, 133, 165, 188, 197]
    distances_to_report = [distances[vertex] if distances[vertex] != sys.maxsize else 1000000 for vertex in vertices_to_report]
    print(",".join(map(str, distances_to_report)))

if __name__ == "__main__":
    main()
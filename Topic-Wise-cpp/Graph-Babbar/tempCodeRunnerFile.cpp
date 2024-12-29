 auto record = st.find(make_pair(dist[neigh.first], neigh.first));

                if (record != st.end())
                {
                    st.erase(record);
                }
